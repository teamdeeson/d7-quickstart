<?php

/**
 * @file
 * Mailsystem settings.
 */

// Default settings
$conf['mail_system'] = array(
  'default-system' => 'MaillogMailSystem',
);
$conf['maillog_send'] = FALSE; // Do not send the email.
$conf['maillog_log'] = TRUE; // Do log the emails.
$conf['maillog_engine'] = 'DefaultMailSystem';

if (SETTINGS_ENVIRONMENT === D_ENVIRONMENT_PROD) {
  $conf['maillog_send'] = TRUE;
  $conf['maillog_log'] = FALSE;
}
elseif (SETTINGS_ENVIRONMENT === D_ENVIRONMENT_TEST) {
  $conf['maillog_send'] = FALSE;
  $conf['maillog_log'] = TRUE;
}
elseif (SETTINGS_ENVIRONMENT === D_ENVIRONMENT_DEV) {
  $conf['maillog_send'] = FALSE;
  $conf['maillog_log'] = TRUE;
}
elseif (SETTINGS_ENVIRONMENT === D_ENVIRONMENT_LOCAL) {
  $conf['maillog_send'] = TRUE;
  $conf['maillog_log'] = TRUE;
}
