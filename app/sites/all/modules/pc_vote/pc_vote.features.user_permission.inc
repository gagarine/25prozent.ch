<?php
/**
 * @file
 * pc_vote.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function pc_vote_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create vote content'.
  $permissions['create vote content'] = array(
    'name' => 'create vote content',
    'roles' => array(
      'administrator' => 'administrator',
      'verified user' => 'verified user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any vote content'.
  $permissions['delete any vote content'] = array(
    'name' => 'delete any vote content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own vote content'.
  $permissions['delete own vote content'] = array(
    'name' => 'delete own vote content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any vote content'.
  $permissions['edit any vote content'] = array(
    'name' => 'edit any vote content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own vote content'.
  $permissions['edit own vote content'] = array(
    'name' => 'edit own vote content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
