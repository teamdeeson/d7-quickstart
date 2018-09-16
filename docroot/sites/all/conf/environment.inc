<?php

$base_domains = array(

  // Docker
  getenv('D4D_HOSTNAME') => 'local',

);

$platform = '';
$instance = $_SERVER['HTTP_HOST'];
$env = $base_domains[$_SERVER['HTTP_HOST']];

if (isset($_SERVER['AH_SITE_ENVIRONMENT']) || isset($_ENV['AH_SITE_ENVIRONMENT'])) {
  $platform = 'acquia';
  if (file_exists('/var/www/site-php/cope_opsmana/cope_opsmana-settings.inc')) {
    require_once '/var/www/site-php/cope_opsmana/cope_opsmana-settings.inc';
  }
}
elseif (isset($_SERVER['PANTHEON_ENVIRONMENT']) || isset($_ENV['PANTHEON_ENVIRONMENT'])) {
  $platform = 'pantheon';
}
elseif (getenv('DOCKER_LOCAL')) {
  $platform = 'docker';
}
elseif (file_exists('/var/www/settings/cope/settings.inc')) {
  $platform = 'vdd';
  require_once '/var/www/settings/cope/settings.inc';
}

if (!empty($env) && !empty($platform) && !empty($instance)) {
  define('SETTINGS_ENVIRONMENT', $env);
  define('SETTINGS_INSTANCE', $instance);
  define('SETTINGS_PLATFORM', $platform);
}
