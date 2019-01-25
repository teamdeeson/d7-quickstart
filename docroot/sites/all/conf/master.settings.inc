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

//  'aggregator',
  'block',
//  'blog',
//  'book',
  'color',
  'comment',
//  'contact',
  'contextual',
  'dashboard',
  'field',
  'field_sql_storage',
  'file',
  'filter',
//  'forum',
  'help',
  'image',
  'list',
//  'locale',
  'menu',
  'node',
  'number',
//  'openid',
  'options',
//  'overlay',
  'path',
//  'php',
//  'poll',
  'rdf',
  'search',
  'shortcut',
  'system',
//  'statistics',
//  'simpletest',
  'taxonomy',
  'text',
//  'toolbar',
//  'tracker',
//  'translation',
//  'trigger',
  'user',

  // Contrib

  'admin_menu',
  'admin_menu_toolbar',
  'admin_views',
  'bean',
  'better_exposed_filters',
  'better_formats',
  'ckeditor',
  'chosen',
  'chr',
  'coffee',
  'ctools',
  'date',
  'diff',
  'entity',
  'entityreference',
  'entityreference_autocomplete',
  'facetapi',
  'fe_block',
  'features',
  'field_group',
  'field_collection',
  'file_entity',
  'fpa',
  'globalredirect',
  'http_proxy',
  'libraries',
  'link',
  'maillog',
  'mailsystem',
  'masquerade',
  'media',
  'media_bulk_upload',
  'media_ckeditor',
  'media_internet',
  'media_vimeo',
  'media_wysiwyg',
  'media_youtube',
  'metatag',
  'module_filter',
  'page_manager',
  'panels',
  'paragraphs',
//  'path_breadcrumbs',
  'pathauto',
  'plupload',
  'publication_date',
  'redirect',
  'role_export',
  'rules',
  'strongarm',
  'token',
  'token_tweaks',
  'trimmed_plaintext',
  'url',
  'variable',
  'variable_admin',
  'views',
  'views_bulk_operations',
  'views_content',
  'xautoload',
  'xmlsitemap',

  // Contrib - Search

  // Uncomment Apache Solr module below if not using Solr via Search API
//  'apachesolr',
//  'apachesolr_access',
//  'apachesolr_infinite_scroll',
//  'apachesolr_search',
  // Uncomment Apache Solr module below if not using Solr via Search API
  'search_api',
  'search_api_solr',

  // Custom & Features


);

if (SETTINGS_ENVIRONMENT === D_ENVIRONMENT_LOCAL) {
  $conf['master_modules']['base'] = array_merge($conf['master_modules']['base'], array(
    // Core
    'dblog',
    'field_ui',
    'update',

    // Contrib
    'bean_ui',
    'mail_debugger',
    'mail_debugger_common',
    'memcache',
    'memcache_admin',
  ));
}

if (SETTINGS_ENVIRONMENT === D_ENVIRONMENT_DEV) {
  $conf['master_modules']['base'] = array_merge($conf['master_modules']['base'], array(
    // Core
    'dblog',
    'field_ui',
    'syslog',

    // Contrib
    'bean_ui',
    'entitycache',
    'memcache',
  ));
}

if (SETTINGS_ENVIRONMENT === D_ENVIRONMENT_TEST) {
  $conf['master_modules']['base'] = array_merge($conf['master_modules']['base'], array(
    // Core
    'dblog',
    'syslog',

    // Contrib
    'bean_ui',
    'entitycache',
    'memcache',
  ));
}

if (SETTINGS_ENVIRONMENT === D_ENVIRONMENT_PROD) {
  $conf['master_modules']['base'] = array_merge($conf['master_modules']['base'], array(
    // Core
    'syslog',

    // Contrib
    'bean_ui',
    'entitycache',
    'memcache',
    'warden',
  ));
}
