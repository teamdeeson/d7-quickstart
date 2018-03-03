<?php

/**
 * @file
 * Aliases for different environments.
 */

if (!isset($drush_major_version)) {
  $drush_version_components = explode('.', DRUSH_VERSION);
  $drush_major_version = $drush_version_components[0];
}

// Docker aliases.

$aliases['docker'] = array(
  'env' => 'docker',
  'root' => '/var/www/html/docroot',
  'uri' => 'localhost',
  'path-aliases' => array(
    '%drush-script' => '/var/www/html/vendor/bin/drush',
  ),
);
