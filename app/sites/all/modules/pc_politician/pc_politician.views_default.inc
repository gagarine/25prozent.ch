<?php
/**
 * @file
 * pc_politician.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function pc_politician_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'candidats';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Candidats';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Candidats';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: party_short */
  $handler->display->display_options['fields']['field_party_short']['id'] = 'field_party_short';
  $handler->display->display_options['fields']['field_party_short']['table'] = 'field_data_field_party_short';
  $handler->display->display_options['fields']['field_party_short']['field'] = 'field_party_short';
  $handler->display->display_options['fields']['field_party_short']['label'] = '';
  $handler->display->display_options['fields']['field_party_short']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_party_short']['group_column'] = 'value';
  /* Field: Content: LINK_facebook */
  $handler->display->display_options['fields']['field_link_facebook']['id'] = 'field_link_facebook';
  $handler->display->display_options['fields']['field_link_facebook']['table'] = 'field_data_field_link_facebook';
  $handler->display->display_options['fields']['field_link_facebook']['field'] = 'field_link_facebook';
  $handler->display->display_options['fields']['field_link_facebook']['label'] = '';
  $handler->display->display_options['fields']['field_link_facebook']['element_label_colon'] = FALSE;
  /* Field: Content: LINK_portrait */
  $handler->display->display_options['fields']['field_link_portrait']['id'] = 'field_link_portrait';
  $handler->display->display_options['fields']['field_link_portrait']['table'] = 'field_data_field_link_portrait';
  $handler->display->display_options['fields']['field_link_portrait']['field'] = 'field_link_portrait';
  $handler->display->display_options['fields']['field_link_portrait']['label'] = '';
  $handler->display->display_options['fields']['field_link_portrait']['element_label_colon'] = FALSE;
  /* Field: Content: LINK_twitter */
  $handler->display->display_options['fields']['field_link_twitter']['id'] = 'field_link_twitter';
  $handler->display->display_options['fields']['field_link_twitter']['table'] = 'field_data_field_link_twitter';
  $handler->display->display_options['fields']['field_link_twitter']['field'] = 'field_link_twitter';
  $handler->display->display_options['fields']['field_link_twitter']['label'] = '';
  $handler->display->display_options['fields']['field_link_twitter']['element_label_colon'] = FALSE;
  /* Field: Content: list */
  $handler->display->display_options['fields']['field_list']['id'] = 'field_list';
  $handler->display->display_options['fields']['field_list']['table'] = 'field_data_field_list';
  $handler->display->display_options['fields']['field_list']['field'] = 'field_list';
  /* Field: Content: list_place_1 */
  $handler->display->display_options['fields']['field_list_place_1']['id'] = 'field_list_place_1';
  $handler->display->display_options['fields']['field_list_place_1']['table'] = 'field_data_field_list_place_1';
  $handler->display->display_options['fields']['field_list_place_1']['field'] = 'field_list_place_1';
  $handler->display->display_options['fields']['field_list_place_1']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_photo']['id'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo']['table'] = 'field_data_field_photo';
  $handler->display->display_options['fields']['field_photo']['field'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_photo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'candidats';
  $translatables['candidats'] = array(
    t('Master'),
    t('Candidats'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('list'),
    t('list_place_1'),
    t('Photo'),
    t('Page'),
  );
  $export['candidats'] = $view;

  return $export;
}
