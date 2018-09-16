<?php

/**
 * @file
 * Settings for the apachesolr module.
 */

if (SETTINGS_ENVIRONMENT === 'local') {
  $conf['apachesolr_default_environment'] = 'acquia_search_server_1';
  if (SETTINGS_PLATFORM === 'docker') {
    $conf['apachesolr_environments']['acquia_search_server_1']['url'] = 'http://solr:8983/solr/core1';
  }
  else {
    $conf['apachesolr_environments']['acquia_search_server_1']['url'] = 'http://localhost:8984/solr/itvpc';
  }
  $conf['apachesolr_environments']['acquia_search_server_1']['name'] = 'Acquia Search';
  $conf['apachesolr_environments']['acquia_search_server_1']['env_id'] = 'acquia_search_server_1';
  $conf['apachesolr_environments']['acquia_search_server_1']['service_class'] = 'DrupalApacheSolrService';
  $conf['acquia_override_subscription']['acquia_override_auto_switch'] = FALSE;

  // Remove the default Solr instance provided by VDD
  if (isset($conf['apachesolr_environments']['solr'])) {
    unset($conf['apachesolr_environments']['solr']);
  }
}
