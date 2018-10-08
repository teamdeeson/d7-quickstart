#!/usr/bin/env bash

script_path=$(dirname $0)
working_dir=$(pwd)
cd "$script_path"
cd ../..
repo_root=$(pwd)

source "$repo_root/.build.env"

if [ "$drupal_version" == "7" ]; then
  drush @docker rr --no-cache-clear \
    && drush @docker updb -y \
    && drush @docker en -y master \
    && drush @docker cc drush \
    && drush @docker master-exec -y \
    && drush @docker cc all \
    && drush @docker cc drush \
    && drush @docker fl
elif [ "$drupal_version" == "8" ]; then
  drush @docker cim sync -y \
    && drush @docker updb -y \
    && drush @docker updb -y --entity-updates \
    && drush @docker cr
fi
