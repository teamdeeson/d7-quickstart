#!/bin/bash
# Cloud Hook: update-db

site="$1"
target_env="$2"
source_branch="$3"
deployed_tag="$4"
repo_url="$5"
repo_type="$6"

declare -a uri
case "${target_env}" in

"prod" )
echo "Prod deploy script"
uri_array=( dev.example.com )
;;

"test" )
echo "Test deploy script"
uri_array=( test.example.com )
;;

"dev" )
echo "Dev deploy script"
uri_array=( www.example.com  )
;;

esac

for uri in "${uri_array[@]}"
do

echo ""
echo "--------------------------------------------------------"
echo "---- START: ${uri}"
echo "--------------------------------------------------------"
echo ""

echo ""
echo "--------------> Clear Drush cache ..."
drush @${site}.${target_env} cc drush --uri=${uri}

echo ""
echo "--------------> Registry Rebuild ..."
drush @${site}.${target_env} rr --uri=${uri} --strict=0

echo ""
echo "--------------> Clear Drush cache ..."
drush @${site}.${target_env} cc drush --uri=${uri}

echo ""
echo "--------------> Master exec ..."
drush @${site}.${target_env} en master --yes --uri=${uri} --strict=0
drush @${site}.${target_env} cc drush --uri=${uri}
drush @${site}.${target_env} master-execute --yes --uri=${uri} --strict=0

echo ""
echo "--------------> Clear Drush cache ..."
drush @${site}.${target_env} cc drush --uri=${uri}

echo ""
echo "--------------> Update DB ..."
drush @${site}.${target_env} updatedb --yes --uri=${uri} --strict=0

echo ""
echo "--------------> Clear all caches ..."
drush @${site}.${target_env} cc all --yes --uri=${uri} --strict=0

echo ""
echo "--------------------------------------------------------"
echo "---- END: ${uri}"
echo "--------------------------------------------------------"
echo ""

done
