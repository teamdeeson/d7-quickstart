<?php

/**
 * @file
 * Redis settings.
 */

$contrib_path = 'sites/all/modules/contrib';

if (SETTINGS_ENVIRONMENT !== D_ENVIRONMENT_LOCAL) {
  $conf['redis_client_interface'] = 'PhpRedis';
  $conf['cache_backends'][] = $contrib_path . '/redis/redis.autoload.inc';
  $conf['cache_default_class'] = 'Redis_Cache';
  $conf['cache_prefix'] = array('default' => 'pantheon-redis');
  // Do not use Redis for cache_form (no performance difference).
  $conf['cache_class_cache_form'] = 'DrupalDatabaseCache';
  // Use Redis for Drupal locks (semaphore).
  $conf['lock_inc'] = $contrib_path . '/redis/redis.lock.inc';
}
elseif (SETTINGS_ENVIRONMENT === D_ENVIRONMENT_LOCAL) {
  $conf['redis_client_base'] = 0;
  $conf['redis_client_interface'] = 'PhpRedis';
  $conf['lock_inc'] = $contrib_path . '/redis/redis.lock.inc';
  $conf['path_inc'] = $contrib_path . '/redis/redis.path.inc';
  $conf['cache_backends'][] = $contrib_path . '/redis/redis.autoload.inc';
  $conf['cache_default_class'] = 'Redis_Cache';
  $conf['cache_class_cache_form'] = 'DrupalDatabaseCache';
  $conf['redis_client_host'] = 'redis';
  $conf['redis_client_port'] = '6379';
}
