<?php
/**
 * @file
 * pc_vote.features.inc
 */

/**
 * Implements hook_node_info().
 */
function pc_vote_node_info() {
  $items = array(
    'vote' => array(
      'name' => t('Vote'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
