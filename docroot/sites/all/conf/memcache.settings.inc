<?php

/**
 * @file
 * Memcache settings.
 */

if (SETTINGS_PLATFORM === 'docker') {
  $conf['cache_backends'][] = './sites/all/modules/contrib/memcache/memcache.inc';
  $conf['cache_default_class'] = 'MemCacheDrupal';
  $conf['cache_class_form'] = 'DrupalDatabaseCache';
  $conf['cache_class_cache_form'] = 'DrupalDatabaseCache';
  $conf['memcache_key_prefix'] = 'docker';
  $conf['memcache_servers'] = array(
    'memcached:11211' => 'default'
  );
  $conf['memcache_bins'] = array(
    'cache' => 'default'
  );
}
//elseif (SETTINGS_PLATFORM === 'acquia') {
//  $conf['cache_backends'][] = './sites/all/modules/contrib/memcache/memcache.inc';
//  $conf['cache_default_class'] = 'MemCacheDrupal';
//  $conf['cache_class_form'] = 'DrupalDatabaseCache';
//  $conf['cache_class_cache_form'] = 'DrupalDatabaseCache';
//}
