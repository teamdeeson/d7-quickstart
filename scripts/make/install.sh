#!/usr/bin/env bash

script_path=$(dirname $0)
working_dir=$(pwd)
cd "$script_path"
cd ../..
repo_root=$(pwd)

source "$repo_root/.build.env"

if [ "$drupal_build" == "Y" ]; then
  docker run -ti -v $repo_root:/var/www/html -w /var/www/html wodby/drupal-php:$drupal_build_php_tag /bin/bash -c "$drupal_build_command"
fi

if [ "$frontend_build" == "Y" ]; then
  docker run -ti -v $repo_root/frontend:/app -w /app deeson/fe-node /bin/bash -c "$frontend_dependency_command"
fi
