<?php
/**
 * @file
 * pc_vote.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function pc_vote_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'candidats_autocomplete';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'candidats_autocomplete';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: party_short */
  $handler->display->display_options['fields']['field_party_short']['id'] = 'field_party_short';
  $handler->display->display_options['fields']['field_party_short']['table'] = 'field_data_field_party_short';
  $handler->display->display_options['fields']['field_party_short']['field'] = 'field_party_short';
  $handler->display->display_options['fields']['field_party_short']['label'] = '';
  $handler->display->display_options['fields']['field_party_short']['element_label_colon'] = FALSE;
  /* Field: Field: Canton */
  $handler->display->display_options['fields']['field_taxo_canton']['id'] = 'field_taxo_canton';
  $handler->display->display_options['fields']['field_taxo_canton']['table'] = 'field_data_field_taxo_canton';
  $handler->display->display_options['fields']['field_taxo_canton']['field'] = 'field_taxo_canton';
  $handler->display->display_options['fields']['field_taxo_canton']['label'] = '';
  $handler->display->display_options['fields']['field_taxo_canton']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_taxo_canton']['type'] = 'taxonomy_term_reference_plain';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Field: Canton (field_taxo_canton) */
  $handler->display->display_options['arguments']['field_taxo_canton_tid']['id'] = 'field_taxo_canton_tid';
  $handler->display->display_options['arguments']['field_taxo_canton_tid']['table'] = 'field_data_field_taxo_canton';
  $handler->display->display_options['arguments']['field_taxo_canton_tid']['field'] = 'field_taxo_canton_tid';
  $handler->display->display_options['arguments']['field_taxo_canton_tid']['default_action'] = 'access denied';
  $handler->display->display_options['arguments']['field_taxo_canton_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_taxo_canton_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_taxo_canton_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_taxo_canton_tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'politician' => 'politician',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'field_party_short' => 'field_party_short',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['candidats_autocomplete'] = $view;

  return $export;
}
