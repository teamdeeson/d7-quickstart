<?php

/**
 * @file
 * Master module.
 */

$conf['master_version'] = 2;
$conf['master_allow_base_scope'] = TRUE;
$conf['master_current_scope'] = 'base';
$conf['master_modules']['base'] = array(
  // Core

  'block',
  'contact',
  'contextual',
  'field',
  'field_sql_storage',
  'file',
  'filter',
  'help',
  'image',
  'list',
  'locale',
  'menu',
  'node',
  'number',
  'options',
  'path',
  'rdf',
  'search',
  'system',
  'taxonomy',
  'text',
  'user',

  // Contrib

//  'addressfield',
//  'advanced_link',
//  'admin_menu',
//  'admin_menu_toolbar',
//  'admin_views',
//  'apachesolr',
//  'apachesolr_access',
//  'apachesolr_infinite_scroll',
//  'apachesolr_search',
//  'autologout',
//  'auto_entitylabel',
//  'bean',
//  'better_exposed_filters',
//  'better_formats',
//  'breakpoints',
//  'brightcove',
//  'brightcove_field',
//  'captcha',
//  'ckeditor',
//  'cdn',
//  'content_taxonomy',
//  'content_taxonomy_autocomplete',
//  'context',
//  'context_metadata',
//  'chosen',
//  'chr',
//  'coffee',
//  'clone',
//  'ctools',
//  'ctools_custom_content',
//  'custom_formatters',
//  'date',
//  'date_api',
//  'date_popup',
//  'date_views',
//  'diff',
//  'ds',
//  'ds_extras',
//  'ds_search',
//  'eck',
//  'email',
//  'email_registration',
//  'entity',
//  'entitycache',
//  'entityqueue',
//  'entity_token',
//  'entityreference',
//  'entityreference_autocomplete',
//  'facetapi',
//  'fe_block',
//  'fe_nodequeue',
//  'features',
//  'features_date_formats',
//  'fences',
//  'field_group',
//  'field_group_list',
//  'field_collection',
//  'file_entity',
//  'flag',
//  'flag_files',
//  'forward',
//  'fpa',
//  'globalredirect',
//  'googleanalytics',
//  'googlenews',
//  'group',
//  'gadd',
//  'gnode',
//  'hide_submit',
//  'http_proxy',
//  'hms_field',
//  'honeypot',
//  'image_captcha',
//  'inactive_user',
//  'libraries',
//  'link',
//  'maillog',
//  'mailsystem',
//  'masquerade',
//  'manualcrop',
//  'media',
//  'media_bulk_upload',
//  'media_ckeditor',
//  'media_internet',
//  'media_vimeo',
//  'media_wysiwyg',
//  'media_youtube',
//  'metatag',
//  'metatag_context',
//  'metatag_opengraph',
//  'menu_block',
//  'module_filter',
//  'nodequeue',
//  'node_clone_tab',
//  'multiform',
//  'page_manager',
//  'panels',
//  'panels_node',
//  'paragraphs',
//  'path_breadcrumbs',
//  'pathauto',
//  'picture',
//  'plupload',
//  'print',
//  'publication_date',
//  'recaptcha',
//  'redirect',
//  'role_export',
//  'rules',
//  'scheduler',
//  'semanticviews',
//  'simple_pass_reset',
//  'speedy',
//  'stringoverrides',
//  'strongarm',
//  'term_queue',
//  'telephone',
//  'textformatter',
//  'timefield',
//  'token',
//  'token_tweaks',
//  'transliteration',
//  'trimmed_plaintext',
//  'twitter_block',
//  'url',
//  'user_registrationpassword',
//  'username_enumeration_prevention',
//  'variable',
//  'variable_admin',
//  'views',
//  'views_bulk_operations',
//  'views_content',
//  'views_infinite_scroll',
//  'xautoload',
//  'xmlsitemap',
//  'youtube',

  // Custom & Features


);

if (SETTINGS_ENVIRONMENT === 'local') {
  $conf['master_modules']['base'] = array_merge($conf['master_modules']['base'], array(
    'dblog',
    'update',
  ));
}

if (SETTINGS_ENVIRONMENT === 'dev') {
  $conf['master_modules']['base'] = array_merge($conf['master_modules']['base'], array(
    'dblog',
    'field_ui',
    'syslog',
  ));
}

if (SETTINGS_ENVIRONMENT === 'test') {
  $conf['master_modules']['base'] = array_merge($conf['master_modules']['base'], array(
    'dblog',
    'syslog',
  ));
}

if (SETTINGS_ENVIRONMENT === 'prod') {
  $conf['master_modules']['base'] = array_merge($conf['master_modules']['base'], array(
    'syslog',
  ));
}
