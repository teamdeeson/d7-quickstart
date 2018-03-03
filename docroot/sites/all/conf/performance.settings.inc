<?php

/**
 * @file
 * Performance settings.
 */

if (in_array(SETTINGS_ENVIRONMENT, array('prod', 'test'))) {
  $conf['cache'] = 1;
  $conf['block_cache'] = 1;
  $conf['preprocess_css'] = 1;
  $conf['preprocess_js'] = 1;
  $conf['jquery_update_compression_type'] = 'min';
  $conf['error_level'] = '0';
}
