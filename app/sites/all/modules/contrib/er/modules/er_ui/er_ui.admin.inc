<?php // $Id$

/**
 * @file
 *
 * Administrative forms and submit handlers for the Entity Relationships module.
 */

/**
 * TODO: Add logic to bounce user to the ER settings form if no entity types are ER-enabled.
 * TODO: Add logic to bounce user to the ER roles form if no ER roles are defined.
 */

/**
 * Form displaying all relationship definitions
 */
function er_ui_definition_admin_form() {
  $defs = entity_load('er_definition', FALSE);

  //TODO: Sort by weight and/or name asc?

  $form = array();

  if (count($defs)) {
    $form['header'] = array(
      '#type' => 'markup',
      '#markup' => '<table><tbody><tr><th>' . t('Relationship Definition') . '</th><th>&nbsp;</th></tr>',
    );
    foreach ($defs as $def) {

      $form[$def->did]['#er_definition'] = $def;
      $form[$def->did]['name'] = array(
        '#markup' => '<tr><td>' . check_plain($def->name) . '</td>',
      );
      //$form[$def->did]['weight'] = array('#type' => 'weight', '#delta' => 10, '#default_value' => $def->weight);
      $form[$def->did]['edit'] = array(
        '#type' => 'link',
        '#title' => t('edit relationship definition'),
        '#href' => "admin/structure/er/definition/$def->did/edit",
        '#prefix' => '<td>',
        '#suffix' => '</td></tr>');
    }

    $form['footer'] = array(
      '#type' => 'markup',
      '#markup' => '</tbody></table>',
    );

  }
  else {
    $form['none'] = array(
      '#type' => 'markup',
      '#markup' => t("There are no relationship definitions available.")
    );
  }

  return $form;
}

/**
 * Form displaying all roles
 */
function er_ui_role_admin_form() {
  $roles = entity_load('er_role', FALSE);

  //TODO: Sort by weight and/or name asc?

  $form = array();

  if (count($roles)) {
    $form['header'] = array(
      '#type' => 'markup',
      '#markup' => '<table><tbody><tr><th>' . t('Role') . '</th><th>&nbsp;</th></tr>',
    );
    foreach ($roles as $role) {
      $form[$role->rid]['#er_role'] = $role;
      $form[$role->rid]['name'] = array(
        '#markup' => '<tr><td>' . check_plain($role->name) . '</td>',
        );
      $form[$role->rid]['edit'] = array(
        '#type' => 'link',
        '#title' => t('edit entity role'),
        '#href' => "admin/structure/er/role/$role->rid/edit",
        '#prefix' => '<td>',
        '#suffix' => '</td></tr>');
    }

    $form['footer'] = array(
      '#type' => 'markup',
      '#markup' => '</tbody></table>',
    );

  }
  else {
    $form['none'] = array(
      '#type' => 'markup',
      '#markup' => t("There are no relationship roles available.")
    );
  }
  return $form;
}

/**
 * Form for adding or editing an Entity Relationship
 */
function er_ui_definition_form($form, &$form_state, $edit = array()) {

  //We need formatter info here
  module_load_include('inc', 'er', 'er.formatters');

  $bundle_options = _er_get_bundle_types(TRUE, TRUE);

  //Get list of all available entity roles
  $roles = er_role_load_multiple(FALSE);
  $role_options = array('' => t('--Select'));
  foreach (array_keys($roles) as $rid) {
    $role_options[$rid] = $roles[$rid]->name;
  }

  $formatter_options = er_formatter_options();

  if (!is_array($edit)) {
    $edit = (array)$edit;
  }
  $edit += array(
    'did' => 0,
    'name' => '',
    'machine_name' => '',
    'description' => '',
    'party_from_rid' => '',
    'party_from_label' => '',
    'formatter_from' => '',
    'party_to_rid' => '',
    'party_to_label' => '',
    'formatter_to' => '',
    'weight' => 0,
    'module' => '',
  );
  $form['#er'] = (object) $edit;
  // Check whether we need a deletion confirmation form.
  if (isset($form_state['confirm_delete']) && isset($form_state['values']['did'])) {
    return er_ui_definition_confirm_delete($form, $form_state, $form_state['values']['did']);
  }
  $form['did'] = array(
    '#type' => 'value',
    '#value' => $edit['did'],
  );
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#default_value' => $edit['name'],
    '#maxlength' => 255,
    '#required' => TRUE,
    '#field_suffix' => ' <small id="edit-name-suffix">&nbsp</small>',
  );
  $form['machine_name'] = array(
    '#type' => 'machine_name',
    '#title' => t('Machine readable name'),
    '#default_value' => $edit['machine_name'],
    '#maxlength' => 255,
    '#description' => t('The unique machine readable name for this relationship definition, can only contain lowercase letters, numbers and underscores.'),
    '#required' => TRUE,
    '#machine_name' => array(
      'exists' => 'er_ui_definition_mn_exists',
    )
  );
  if ($edit['did']) {
    $form['machine_name']['#disabled'] = TRUE;
  }
  $form['description'] = array(
    '#type' => 'textfield',
    '#title' => t('Description'),
    '#default_value' => $edit['description'],
  );

  $form['from'] = array(
    '#type' => 'fieldset',
    '#title' => t('From'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $form['from']['party_from_rid'] = array(
    '#type' => 'select',
    '#title' => t("Party 'From' Role"),
    '#default_value' => $edit['party_from_rid'],
    '#required' => TRUE,
    '#options' => $role_options,
  );
  if ($edit['did']) {
    $form['from']['party_from_rid']['#disabled'] = TRUE;
  }

  $form['from']['party_from_bundle'] = array(
    '#type' => 'select',
    '#title' => t("Party 'From' Type"),
    '#default_value' => isset($edit['party_from_bundle']) ? $edit['party_from_bundle'] : '',
    '#required' => TRUE,
    '#options' => $bundle_options
  );
  if ($edit['did']) {
    $form['from']['party_from_bundle']['#disabled'] = TRUE;
  }
  /* TODO: add token support to the from / to label fields. */

  $form['from']['party_from_label'] = array(
    '#type' => 'textfield',
    '#title' => t("Party 'From' Label"),
    '#maxlength' => 255,
    '#description' => t("Describes how the 'From' party relates to the 'To' party; for example, <tt>from</tt> \"is the parent of\" <tt>to</tt>"),
    '#default_value' => $edit['party_from_label'],
    '#required' => TRUE,
  );

  $form['from']['formatter_from'] = array(
    '#type' => 'select',
    '#title' => t('Formatter'),
    '#options' => $formatter_options,
    '#default_value' => $edit['formatter_from'],
    '#required' => TRUE,
    '#description' => t('This formatter will be used when displaying instances of this relationship when this entity is on the FROM side.'),
  );

  /* TODO: Support for checkboxes allowing relationship instances to be
   * shown/hidden when hook_entity_view() is called and the entity being view is
   * on the FROM or TO side of the relationship
   */

  $form['to'] = array(
    '#type' => 'fieldset',
    '#title' => t('to'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $form['to']['party_to_rid'] = array(
    '#type' => 'select',
    '#title' => t("Party 'To' Role"),
    '#default_value' => $edit['party_to_rid'],
    '#required' => TRUE,
    '#options' => $role_options,
  );
  if ($edit['did']) {
    $form['to']['party_to_rid']['#disabled'] = TRUE;
  }
  $form['to']['party_to_bundle'] = array(
    '#type' => 'select',
    '#title' => t("Party 'To' Type"),
    '#default_value' => isset($edit['party_to_bundle']) ? $edit['party_to_bundle'] : '',
    '#required' => TRUE,
    '#options' => $bundle_options
  );
  if ($edit['did']) {
    $form['to']['party_to_bundle']['#disabled'] = TRUE;
  }
  $form['to']['party_to_label'] = array(
    '#type' => 'textfield',
    '#title' => t("Party 'To' Label"),
    '#maxlength' => 255,
    '#description' => t("Describes how the 'To' party relates to the 'From' party; for example, <tt>to</tt> \"is the child of\" <tt>from</tt>"),
    '#default_value' => $edit['party_to_label'],
    '#required' => TRUE,
  );
  $form['to']['formatter_to'] = array(
    '#type' => 'select',
    '#title' => t('Formatter'),
    '#options' => $formatter_options,
    '#default_value' => $edit['formatter_to'],
    '#required' => TRUE,
    '#description' => t('This formatter will be used when displaying instances of this relationship when this entity is on the TO side.'),
  );
  /* TODO: Support for a checkbox allowing for 'from' relationships to be
   * displayed in their own content item when matching entity type is being
   * displayed (hook_entity_load? hook_entity_prepare_view?)
   */

  $form['submit'] = array('#type' => 'submit', '#value' => t('Save'));
  if (isset($edit['did'])) {
    $form['delete'] = array('#type' => 'submit', '#value' => t('Delete'));
    $form['did'] = array('#type' => 'value', '#value' => $edit['did']);
    $form['module'] = array('#type' => 'value', '#value' => $edit['module']);
  }

  return $form;
}

/**
 * Form builder for the relationship definition delete confirmation form.
 *
 * @ingroup forms
 * @see er_ui_definition_confirm_delete_submit()
 */
function er_ui_definition_confirm_delete($form, &$form_state, $did) {
  $def = er_definition_load($did);

  $form['#id'] = 'er_ui_definition_confirm_delete';
  $form['type'] = array('#type' => 'value', '#value' => 'er');
  $form['did'] = array('#type' => 'value', '#value' => $did);
  $form['name'] = array('#type' => 'value', '#value' => $def->name);
  $form['#submit'] = array('er_ui_definition_confirm_delete_submit');
  return confirm_form($form,
                  t('Are you sure you want to delete the relationship definition %title?',
                  array('%title' => $def->name)),
                    'admin/structure/er/definition',
                  t('Deleting a relationship definition will delete all entity
                    relationship instances associated with it. This action cannot be undone.'),
                  t('Delete'),
                  t('Cancel'));
}

/**
 * Submit handler to delete a relationship definition after confirmation.
 *
 * @see er_ui_definition_confirm_delete()
 */
function er_ui_definition_confirm_delete_submit($form, &$form_state) {
  $status = er_definition_delete($form_state['values']['did']);
  drupal_set_message(t('Deleted relationship definition %name.', array('%name' => $form_state['values']['name'])));
  watchdog('er', 'Deleted relationship definition %name.', array('%name' => $form_state['values']['name']), WATCHDOG_NOTICE);
  $form_state['redirect'] = 'admin/structure/er';
  return;
}

/**
 * Accept the form submission for a relationship definition and save the results.
 *
 * TODO: add logic to delete existing instances if the from or to bundle type
 * of an existing relationship definition is being changed here
 *
 */
function er_ui_definition_form_submit($form, &$form_state) {
  $old_def = $form['#er'];
  if ($form_state['clicked_button']['#value'] == t('Delete')) {
    // Rebuild the form to confirm role deletion.
    $form_state['rebuild'] = TRUE;
    $form_state['confirm_delete'] = TRUE;
    return;
  }

  // Get info about the FROM and TO bundles' entity types; we store the bundle
  // for use by the er_definition form, and type for use by entity_load
  // everywhere else.
  $entity_info = entity_get_info();

  foreach ($entity_info as $entity => $info) {
    if (in_array($form_state['values']['party_from_bundle'], array_keys($info['bundles']))) {
      $form_state['values']['party_from_type'] = $entity;
    }
    if (in_array($form_state['values']['party_to_bundle'], array_keys($info['bundles']))) {
      $form_state['values']['party_to_type'] = $entity;
    }
  }

  $def = (object) $form_state['values'];
  switch (er_definition_save($def)) {
    case SAVED_NEW:
      drupal_set_message(t('Created new relationship definition %name.', array('%name' => $def->name)));
      watchdog('er', 'Created new relationship definition %name.', array('%name' => $def->name), WATCHDOG_NOTICE, l(t('edit'), 'admin/structure/er/definition/' . $def->did));
      break;
    case SAVED_UPDATED:
      drupal_set_message(t('Updated relationship definition %name.', array('%name' => $def->name)));
      watchdog('er', 'Updated relationship definition %name.', array('%name' => $def->name), WATCHDOG_NOTICE, l(t('edit'), 'admin/structure/er/definition/' . $def->did));
      break;
  }

  $form_state['did'] = $def->did;
  $form_state['redirect'] = 'admin/structure/er';
  return;
}

/**
 * Form for adding or editing an entity Role
 */
function er_ui_role_form($form, &$form_state, $edit = array()) {

  //Build user roles select options
  $roles = user_roles();
  $roles = array_reverse($roles, TRUE);
  $roles[''] = t('--Select--');
  $roles = array_reverse($roles, TRUE);

  if (!is_array($edit)) {
    $edit = (array)$edit;
  }
  $edit += array(
    'rid' => 0,
    'name' => '',
    'machine_name' => '',
    'name_plural' => '',
    'description' => '',
    //'user_rid' => '',
    'weight' => 0,
  );

  $form['#er_role'] = (object) $edit;
  // Check whether we need a deletion confirmation form.
  if (isset($form_state['confirm_delete']) && isset($form_state['values']['rid'])) {
    return er_ui_role_confirm_delete($form, $form_state, $form_state['values']['rid']);
  }
  $form['rid'] = array(
    '#type' => 'value',
    '#value' => $edit['rid'],
  );
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#default_value' => $edit['name'],
    '#maxlength' => 255,
    '#required' => TRUE,
    '#field_suffix' => ' <small id="edit-name-suffix">&nbsp</small>',
  );
  $form['machine_name'] = array(
    '#type' => 'machine_name',
    '#title' => t('Machine readable name'),
    '#default_value' => $edit['machine_name'],
    '#maxlength' => 255,
    '#description' => t('The unique machine readable name for this entity role, can only contain lowercase letters, numbers and underscores.'),
    '#required' => TRUE,
    '#machine_name' => array(
      'exists' => 'er_ui_role_mn_exists'
    )
  );
  if ($edit['rid']) {
    $form['machine_name']['#disabled'] = TRUE;
  }
  $form['name_plural'] = array(
    '#type' => 'textfield',
    '#title' => t('Plural Name'),
    '#default_value' => $edit['name_plural'],
    '#maxlength' => 255,
    '#required' => TRUE,
    '#description' => t('(Useful for building lists of related entities)'),
  );
  $form['description'] = array(
    '#type' => 'textfield',
    '#title' => t('Description'),
    '#default_value' => $edit['description'],
  );

  //  Disabled until there's a practical application/demonstration
  //  $form['user_rid'] = array(
  //    '#type' => 'select',
  //    '#title' => t('Corresponding User Role'),
  //    '#default_value' => $edit['user_rid'],
  //    '#options' => $roles,
  //    '#required' => FALSE,
  //  );
  $form['user_rid'] = array(
    '#type' => 'value',
    '#value' => 0,
  );

  $form['submit'] = array('#type' => 'submit', '#value' => t('Save'));
  if (isset($edit['rid'])) {
    $form['delete'] = array('#type' => 'submit', '#value' => t('Delete'));
    $form['rid'] = array('#type' => 'value', '#value' => $edit['rid']);
  //  $form['module'] = array('#type' => 'value', '#value' => $edit['module']);
  }

  return $form;
}

/**
 * Form builder for the entity role delete confirmation form.
 *
 * @ingroup forms
 * @see er_ui_role_confirm_delete_submit()
 */
function er_ui_role_confirm_delete($form, &$form_state, $rid) {
  $role = er_role_load($rid);

  $form['#id'] = 'er_ui_role_confirm_delete';
  $form['type'] = array('#type' => 'value', '#value' => 'er_role');
  $form['rid'] = array('#type' => 'value', '#value' => $rid);
  $form['name'] = array('#type' => 'value', '#value' => $role->name);
  $form['#submit'] = array('er_ui_role_confirm_delete_submit');
  return confirm_form($form,
                  t('Are you sure you want to delete the entity role %title?',
                  array('%title' => $role->name)),
                  'admin/structure/er/role',
                  t('Deleting an entity role will delete all entity relationship
                    instances associated with it. This action cannot be undone.'),
                  t('Delete'),
                  t('Cancel'));
}

/**
 * Submit handler to delete an entity role after confirmation.
 *
 * @see er_ui_role_confirm_delete()
 */
function er_ui_role_confirm_delete_submit($form, &$form_state) {
  $status = er_role_delete($form_state['values']['rid']);
  drupal_set_message(t('Deleted entity role %name.', array('%name' => $form_state['values']['name'])));
  watchdog('er', 'Deleted entity role %name.', array('%name' => $form_state['values']['name']), WATCHDOG_NOTICE);
  $form_state['redirect'] = 'admin/structure/er/role';
  return;
}

/**
 * Accept the form submission for an entity role and save the results.
 */
function er_ui_role_form_submit($form, &$form_state) {
  $old_role = $form['#er_role'];
  if ($form_state['clicked_button']['#value'] == t('Delete')) {
    // Rebuild the form to confirm role deletion.
    $form_state['rebuild'] = TRUE;
    $form_state['confirm_delete'] = TRUE;
    return;
  }
  $role = (object) $form_state['values'];
  switch (er_role_save($role)) {
    case SAVED_NEW:
      drupal_set_message(t('Created new entity role %name.', array('%name' => $role->name)));
      watchdog('er', 'Created new entity role %name.', array('%name' => $role->name), WATCHDOG_NOTICE, l(t('edit'), 'admin/structure/er/role/' . $role->rid));
      break;
    case SAVED_UPDATED:
      drupal_set_message(t('Updated entity role %name.', array('%name' => $role->name)));
      watchdog('er', 'Updated entity role %name.', array('%name' => $role->name), WATCHDOG_NOTICE, l(t('edit'), 'admin/structure/er/role/' . $role->rid));
      break;
  }

  $form_state['rid'] = $role->rid;
  $form_state['redirect'] = 'admin/structure/er/role';
  return;
}

/**
 * Form builder for the ER admin settings form.
 *
 * @ingroup forms
 */
function er_ui_settings_form($form, &$form_state) {
  //TODO: disable unchecking of entity types already being used by relationship definitions

  $er_active_bundles = variable_get('er_active_bundles', array('node', 'user'));

  $form = array();
  $form['#redirect'] = FALSE;
  $form['er_active_bundles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Entity types which can be used by Entity Relationships'),
    '#default_value' => $er_active_bundles,
    '#options' => _er_get_bundle_types(FALSE, FALSE),
    '#description' => t("This setting controls which entity types are available when adding or editing Relationship Definitions."),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * Accept the form submission for the ER admin settings and update the results.
 */
function er_ui_settings_form_submit($form, &$form_state) {

  //Purge types with empty values
  $types = array_flip($form_state['values']['er_active_bundles']);
  unset($types[0]);
  variable_set('er_active_bundles', array_keys($types));
  drupal_set_message(t("Entity Relationships settings saved."));

}

/**
 * Check ER definition machine name availability
 */
function er_ui_definition_mn_exists($machine_name) {
  return er_ui_machine_name_exists($machine_name, 'er_definition');
}

/**
 * Check ER role machine name availability
 */
function er_ui_role_mn_exists($machine_name) {
  return er_ui_machine_name_exists($machine_name, 'er_role');
}
/**
 * Check availability of a machine name in the specified table
 */
function er_ui_machine_name_exists($machine_name, $table) {
  $query = db_select($table);
  $query->addField($table, 'machine_name');
  $query->condition('machine_name', $machine_name, '=');
  $result = $query->execute();
  return $result->rowCount();
}