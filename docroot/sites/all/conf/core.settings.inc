<?php

/**
 * @file
 * Core settings.
 */

$conf['404_fast_paths_exclude'] = '/\/(?:styles)|(?:system\/files)\//';
$conf['404_fast_paths'] = '/\.(?:txt|png|gif|jpe?g|css|js|ico|swf|flv|cgi|bat|pl|dll|exe|asp)$/i';
$conf['404_fast_html'] = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN" "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd"><html xmlns="http://www.w3.org/1999/xhtml"><head><title>404 Not Found</title></head><body><h1>Not Found</h1><p>The requested URL "@path" was not found on this server.</p></body></html>';

drupal_fast_404();

$update_free_access = FALSE;
$drupal_hash_salt = '';

$base_url = 'https://' . SETTINGS_INSTANCE;

// Never run poormanscron.
$conf['cron_safe_threshold'] = '0';

// Token tweaks.
$conf['token_tree_recursion_limit'] = '4';

// Regional settings.
$conf['site_default_country'] = 'GB';
$conf['date_first_day'] = '1';
$conf['date_default_timezone'] = 'Europe/London';
$conf['configurable_timezones'] = '0';
$conf['date_format_medium'] = 'jS F Y';

if (SETTINGS_PLATFORM === D_PLATFORM_DOCKER) {
  $conf['file_temporary_path'] = '/tmp';
  $conf['file_public_path'] = 'sites/default/files';
  $conf['file_private_path'] = '../.persist/private/';
}
