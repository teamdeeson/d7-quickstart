<?php

const D_ENVIRONMENT_LOCAL = 'local';
const D_ENVIRONMENT_DEV = 'dev';
const D_ENVIRONMENT_TEST = 'test';
const D_ENVIRONMENT_PROD = 'prod';

const D_PLATFORM_DOCKER = 'docker';
const D_PLATFORM_PIPELINES = 'pipelines';
const D_PLATFORM_ACQUIA = 'acquia';
const D_PLATFORM_PANTHEON = 'pantheon';
const D_PLATFORM_PLATFORMSH = 'platformsh';

$base_domains = array(

  // Docker
  getenv('D4D_HOSTNAME') => D_ENVIRONMENT_LOCAL,

);

$platform = '';
$instance = $_SERVER['HTTP_HOST'];
$env = $base_domains[$_SERVER['HTTP_HOST']];

if (isset($_SERVER['AH_SITE_ENVIRONMENT']) || isset($_ENV['AH_SITE_ENVIRONMENT'])) {
  $platform = D_PLATFORM_ACQUIA;
  $acquia_settings_file = '/var/www/site-php/my_project/my_project-settings.inc';
  if (file_exists($acquia_settings_file)) {
    require_once $acquia_settings_file;
  }
}
elseif (isset($_SERVER['PANTHEON_ENVIRONMENT']) || isset($_ENV['PANTHEON_ENVIRONMENT'])) {
  $platform = D_PLATFORM_PANTHEON;
}
elseif (getenv('DOCKER_LOCAL')) {
  $platform = D_PLATFORM_DOCKER;
}

if (!empty($env) && !empty($platform)) {
  if (empty($instance) && php_sapi_name() != 'cli') {
    if (function_exists('drupal_set_message')) {
      drupal_set_message('SETTINGS_INSTANCE is not set and we were not invoked from the CLI.', 'warning');
    }
  }
  define('SETTINGS_PLATFORM', $platform);
  define('SETTINGS_ENVIRONMENT', $env);
  define('SETTINGS_INSTANCE', $instance);
}
else {
  if (function_exists('drupal_set_message')) {
    drupal_set_message('SETTINGS_PLATFORM and/or SETTINGS_ENVIRONMENT is not set.', 'error');
  }
}
