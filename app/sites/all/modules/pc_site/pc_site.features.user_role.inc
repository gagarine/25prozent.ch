<?php
/**
 * @file
 * pc_site.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function pc_site_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: unverified user.
  $roles['unverified user'] = array(
    'name' => 'unverified user',
    'weight' => 4,
  );

  // Exported role: verified user.
  $roles['verified user'] = array(
    'name' => 'verified user',
    'weight' => 3,
  );

  return $roles;
}
