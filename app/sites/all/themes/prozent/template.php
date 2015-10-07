<?php
/**
 * @file
 * template.php
 */

/**
* Preprocess variables for node.tpl.php
*
* @see node.tpl.php
*/
function prozent_preprocess_node(&$variables) {


}


function prozent_form_user_register_form_alter(&$form, &$form_state, $form_id) {
    $form['sms_user']['gateway']['country']['#type'] = 'value';
    $form['sms_user']['gateway']['country']['#value'] = 41;
    $form['sms_user']['number']['#description'] = t('You will receive a message to confirm your mobile information upon login.');
    unset($form['sms_user']['#type']);
}