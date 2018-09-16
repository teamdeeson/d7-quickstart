#!/usr/bin/env bash

cwd=$(pwd)
script_path=$(dirname $0)
cd "$script_path" && cd ../..

composer install
chmod u+w docroot/sites/* docroot/sites/*/settings.php

cd docroot \
  && ../vendor/bin/drush @none make -y --nocolor --no-recursion ../drush-make.yml
