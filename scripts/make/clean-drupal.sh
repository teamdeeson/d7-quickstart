#!/usr/bin/env bash

set -e

script_path=$(dirname $0)
working_dir=$(pwd)
cd "$script_path"
cd ../..
repo_root=$(pwd)

source "$repo_root/.build.env"

if [ "$drupal_version" == "7" ]; then
  rm -rf docroot/includes
  rm -rf docroot/misc
  rm -rf docroot/modules
  rm -rf docroot/scripts
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
  rm -rf docroot/pantheon.upstream.yml
  rm -rf docroot/*.patch
  rm -rf docroot/sites/example.sites.php
  rm -rf docroot/sites/README.txt
  rm -rf docroot/sites/default/default.settings.php
  rm -rf docroot/sites/all/libraries/README.txt
  rm -rf docroot/sites/all/modules/contrib
  rm -rf docroot/sites/all/modules/README.txt
  rm -rf docroot/sites/all/themes/contrib
  rm -rf docroot/sites/all/themes/README.txt

  if [ "$drupal_alternative_theme_engine" == "Y" ]; then
    rm -rf docroot/themes/bartik
    rm -rf docroot/themes/garland
    rm -rf docroot/themes/seven
    rm -rf docroot/themes/stark
    rm -rf docroot/themes/engines/phptemplate
  else
    rm -rf docroot/themes
  fi

  if [ "$drupal_custom_profile" == "Y" ]; then
    rm -rf docroot/profiles/README.txt
    rm -rf docroot/profiles/minimal
    rm -rf docroot/profiles/standard
    rm -rf docroot/profiles/testing
  else
    rm -rf docroot/profiles

  fi

elif [ "$drupal_version" == "8" ]; then
  rm -Rf docroot web
fi
