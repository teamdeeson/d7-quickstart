#!/usr/bin/env bash

script_path=$(dirname $0)
working_dir=$(pwd)
cd "$script_path"
cd ../..
repo_root=$(pwd)

source "$repo_root/.build.env"

if [ "$frontend_build" == "Y" ]; then
  docker run -ti -v $repo_root/frontend:/app -w /app "$frontend_build_tag" /bin/bash -c "$frontend_build_command"
fi
