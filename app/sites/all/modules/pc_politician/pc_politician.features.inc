<?php
/**
 * @file
 * pc_politician.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pc_politician_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_views_api().
 */
function pc_politician_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

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
