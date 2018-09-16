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

if (SETTINGS_ENVIRONMENT == 'prod') {
  $conf['maillog_send'] = TRUE;
  $conf['maillog_log'] = FALSE;
}
elseif (SETTINGS_ENVIRONMENT == 'test') {
  $conf['maillog_send'] = FALSE;
  $conf['maillog_log'] = TRUE;
}
elseif (SETTINGS_ENVIRONMENT == 'dev') {
  $conf['maillog_send'] = FALSE;
  $conf['maillog_log'] = TRUE;
}
elseif (SETTINGS_ENVIRONMENT == 'local') {
  $conf['maillog_send'] = TRUE;
  $conf['maillog_log'] = TRUE;
}
