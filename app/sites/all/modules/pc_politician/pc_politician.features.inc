<?php
/**
 * @file
 * pc_politician.features.inc
 */

/**
 * Implements hook_node_info().
 */
function pc_politician_node_info() {
  $items = array(
    'politician' => array(
      'name' => t('Politician'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Full name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
