#!/usr/bin/env bash

set -e

script_path=$(dirname $0)
working_dir=$(pwd)
cd "$script_path"

if [ ! -d "./make" ]; then
  docker run -v $(pwd):/app -w /app deeson/deployer /bin/bash -c 'git clone https://github.com/teamdeeson/drupal-build-framework.git make && rm -Rf ./make/.git'
fi
