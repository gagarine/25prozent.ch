<?php
/**
 * @file
 * pc_politician.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function pc_politician_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create politician content'.
  $permissions['create politician content'] = array(
    'name' => 'create politician content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any politician content'.
  $permissions['delete any politician content'] = array(
    'name' => 'delete any politician content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own politician content'.
  $permissions['delete own politician content'] = array(
    'name' => 'delete own politician content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in list_nam'.
  $permissions['delete terms in list_nam'] = array(
    'name' => 'delete terms in list_nam',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in party'.
  $permissions['delete terms in party'] = array(
    'name' => 'delete terms in party',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any politician content'.
  $permissions['edit any politician content'] = array(
    'name' => 'edit any politician content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own politician content'.
  $permissions['edit own politician content'] = array(
    'name' => 'edit own politician content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in list_nam'.
  $permissions['edit terms in list_nam'] = array(
    'name' => 'edit terms in list_nam',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in party'.
  $permissions['edit terms in party'] = array(
    'name' => 'edit terms in party',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
