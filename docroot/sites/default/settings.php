<?php

/**
 * @file
 * Default Drupal configuration file sites/default/settings.php.
 *
 * You should not normally need to modify this file.
 */

// Detect the environment.
require_once DRUPAL_ROOT . '/sites/all/conf/environment.inc';

// Configure the application.
foreach (glob(DRUPAL_ROOT . '/sites/all/conf/*.settings.inc') as $file) {
  require_once $file;
}
