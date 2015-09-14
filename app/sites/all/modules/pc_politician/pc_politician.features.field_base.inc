<?php
/**
 * @file
 * pc_politician.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function pc_politician_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_link_portrait'
  $field_bases['field_link_portrait'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_link_portrait',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
