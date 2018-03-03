HOST=php
COMMAND=/bin/bash

# Remove everything that's re-buildable. Running make build will reverse this.
clean: clean-drupal clean-composer

clean-composer:
        rm -rf vendor bin

clean-drupal:
        rm -rf docroot/includes
        rm -rf docroot/misc
        rm -rf docroot/modules
        rm -rf docroot/profiles
        rm -rf docroot/scripts
        rm -rf docroot/themes
        rm -rf docroot/.htaccess
        rm -rf docroot/.editorconfig
        rm -rf docroot/.gitignore
        rm -rf docroot/authorize.php
        rm -rf docroot/CHANGELOG.txt
        rm -rf docroot/COPYRIGHT.txt
        rm -rf docroot/cron.php
        rm -rf docroot/index.php
        rm -rf docroot/INSTALL.mysql.txt
        rm -rf docroot/INSTALL.pgsql.txt
        rm -rf docroot/install.php
        rm -rf docroot/INSTALL.sqlite.txt
        rm -rf docroot/INSTALL.txt
        rm -rf docroot/LICENSE.txt
        rm -rf docroot/MAINTAINERS.txt
        rm -rf docroot/PATCHES.txt
        rm -rf docroot/README.txt
        rm -rf docroot/robots.txt
        rm -rf docroot/update.php
        rm -rf docroot/UPGRADE.txt
        rm -rf docroot/web.config
        rm -rf docroot/xmlrpc.php
        rm -rf docroot/*.patch
        rm -rf docroot/sites/example.sites.php
        rm -rf docroot/sites/README.txt
        rm -rf docroot/sites/default/default.settings.php
        rm -rf docroot/sites/all/libraries/README.txt
        rm -rf docroot/sites/all/modules/contrib
        rm -rf docroot/sites/all/modules/README.txt
        rm -rf docroot/sites/all/themes/contrib
        rm -rf docroot/sites/all/themes/README.txt

install:
	composer install

# Download and compile all the project's assets.
build:  build-drupal

# Drupal

build-drupal:
        ./scripts/build-drupal.sh

build-solr:
        make docker-shell HOST=solr COMMAND='make core=core1 -f /usr/local/bin/actions.mk'

# Start docker
docker-start: docker-up
docker-up: docker-local-ssl
	docker-compose up -d

# Stop docker
docker-stop: docker-down
docker-down:
	docker-compose down

# Restart docker
docker-restart: docker-stop docker-start

docker-local-ssl: .persist/certs/local.key .persist/certs/local.crt
.persist/certs/local.%:
	mkdir -p ./.persist/certs
	./scripts/make/genlocalcrt.sh ./.persist/certs

build-solr:
	make docker-shell HOST=solr COMMAND='make core=core1 config_set=apachesolr -f /usr/local/bin/actions.mk'

# Connect to the shell on a docker host, defaults to HOST=php COMMAND=/bin/bash
# Usage: make docker-shell HOST=[container name] COMMAND=[command]
docker-shell:
	docker exec -i -t `docker ps | grep $(HOST)_1 | cut -d' ' -f 1` $(COMMAND)
