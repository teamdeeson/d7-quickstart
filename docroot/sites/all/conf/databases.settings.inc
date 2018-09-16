<?php

/**
 * @file
 * Database connection information.
 */

if (SETTINGS_PLATFORM === 'docker') {
  // Database.
  $databases['default']['default'] = array(
    'database' => getenv('DB_NAME'),
    'username' => getenv('DB_USER'),
    'password' => getenv('DB_PASSWORD'),
    'prefix' => '',
    'host' => getenv('DB_HOST'),
    'port' => '3306',
    'driver' => getenv('DB_DRIVER'),
  );
}
