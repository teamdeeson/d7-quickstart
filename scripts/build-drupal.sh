#!/usr/bin/env bash

script_path=$(dirname $0)
base_path=$(dirname ${script_path})

cd ${base_path}

composer install
chmod u+w docroot/sites/* docroot/sites/*/settings.php

cd docroot && ../vendor/bin/drush @none -y --nocolor make ../drush-make.yml
