#!/usr/bin/env bash

script_path=$(dirname $0)
working_dir=$(pwd)
cd "$script_path"
cd ../..
repo_root=$(pwd)

docker run -ti -v $repo_root:/var/www/html -w /var/www/html wodby/drupal-php:7.0-2.1.0 /bin/bash -c './scripts/make/build-drupal.sh' #\
  #&& docker run -ti -v $repo_root/frontend:/app -w /app deeson/fe-node /bin/bash -c 'npm install && ./node_modules/.bin/grunt build'
