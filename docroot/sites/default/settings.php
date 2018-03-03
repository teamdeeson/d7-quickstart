<?php

/**
 * @file
 * The default settings.php loads in real settings.
 */

$base_domains = array(
  // Docker.
  'localhost' => 'local',
);

$platform = '';
$instance = $_SERVER['HTTP_HOST'];
$env = $base_domains[$_SERVER['HTTP_HOST']];

if (isset($_SERVER['AH_SITE_ENVIRONMENT']) || isset($_ENV['AH_SITE_ENVIRONMENT'])) {
  $platform = 'acquia';
  if (file_exists('/var/www/site-php/itvpc/itvpc-settings.inc')) {
    require_once '/var/www/site-php/itvpc/itvpc-settings.inc';
  }
}
elseif (isset($_SERVER['PANTHEON_ENVIRONMENT']) || isset($_ENV['PANTHEON_ENVIRONMENT'])) {
  $platform = 'pantheon';
}
elseif (stripos($instance,'.dev') !== FALSE) {
  $vdd_settings_file = '/var/www/settings/' . str_replace('.dev', '', $instance) . '/settings.inc';
  if (file_exists($vdd_settings_file)) {
    require_once $vdd_settings_file;
    $platform = 'vdd';
  }
}
elseif (getenv('DOCKER_LOCAL')) {
  $platform = 'docker';
}

if (!empty($env) && !empty($platform) && !empty($instance)) {
  define('SETTINGS_ENVIRONMENT', $env);
  define('SETTINGS_INSTANCE', $instance);
  define('SETTINGS_PLATFORM', $platform);

  foreach (glob('sites/all/conf/*.settings.inc') as $file) {
    require_once $file;
  }
}
