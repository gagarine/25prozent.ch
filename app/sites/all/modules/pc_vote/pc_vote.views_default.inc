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
  $handler->display->display_options['fields']['field_party_short']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_party_short']['group_column'] = 'value';
  /* Field: Field: Swiss canton of residency */
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
  /* Contextual filter: Field: Swiss canton of residency (field_taxo_canton) */
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
  $translatables['candidats_autocomplete'] = array(
    t('Master'),
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
    t('All'),
    t('Entity Reference'),
  );
  $export['candidats_autocomplete'] = $view;

  $view = new view();
  $view->name = 'list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Electoral list';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create vote content';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '400';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'nothing',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'information';
  $handler->display->display_options['header']['area']['content'] = '<div class="bs-callout bs-callout-warning">
  <h4>Select a list or pick candidates individually</h4>
<p>You can <a href="/node/add/vote"><strong>pick each candidate individually</strong></a> or chose a list below.</p>
<p>If you choose a list, you can modify it (adding or removing candidate from the list) in the next step before validating your vote.</p>
<p>You don\'t know which candidates can represent you the best? <a target="_blank" href="https://smartvote.ch">Smartvote.ch</a> can help you choose.
</div>



';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'term list name';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'list_nam' => 'list_nam',
    'canton' => 0,
    'party' => 0,
    'tags' => 0,
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  /* Field: button list select */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'button list select';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Chose "[name]"';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'node/add/vote?listid=[tid]';
  $handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'btn btn-primary  btn-list-select';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Title: (politician name) */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Title: (politician name)';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: list_place_1 */
  $handler->display->display_options['fields']['field_list_place_1']['id'] = 'field_list_place_1';
  $handler->display->display_options['fields']['field_list_place_1']['table'] = 'field_data_field_list_place_1';
  $handler->display->display_options['fields']['field_list_place_1']['field'] = 'field_list_place_1';
  $handler->display->display_options['fields']['field_list_place_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_list_place_1']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'term_node_tid';
  /* Sort criterion: Content: list_place_1 (field_list_place_1) */
  $handler->display->display_options['sorts']['field_list_place_1_value']['id'] = 'field_list_place_1_value';
  $handler->display->display_options['sorts']['field_list_place_1_value']['table'] = 'field_data_field_list_place_1';
  $handler->display->display_options['sorts']['field_list_place_1_value']['field'] = 'field_list_place_1_value';
  /* Contextual filter: Field: Swiss canton of residency (field_taxo_canton) */
  $handler->display->display_options['arguments']['field_taxo_canton_tid']['id'] = 'field_taxo_canton_tid';
  $handler->display->display_options['arguments']['field_taxo_canton_tid']['table'] = 'field_data_field_taxo_canton';
  $handler->display->display_options['arguments']['field_taxo_canton_tid']['field'] = 'field_taxo_canton_tid';
  $handler->display->display_options['arguments']['field_taxo_canton_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_taxo_canton_tid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_taxo_canton_tid']['default_argument_options']['code'] = 'global $user;
$term= user_load($user->uid)->field_taxo_canton;
return $term[\'und\'][0][\'tid\'];';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'electoral-list';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Vote now!';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['list'] = array(
    t('Master'),
    t('Electoral list'),
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
    t('information'),
    t('<div class="bs-callout bs-callout-warning">
  <h4>Select a list or pick candidates individually</h4>
<p>You can <a href="/node/add/vote"><strong>pick each candidate individually</strong></a> or chose a list below.</p>
<p>If you choose a list, you can modify it (adding or removing candidate from the list) in the next step before validating your vote.</p>
<p>You don\'t know which candidates can represent you the best? <a target="_blank" href="https://smartvote.ch">Smartvote.ch</a> can help you choose.
</div>



'),
    t('term list name'),
    t('.'),
    t(','),
    t('Chose "[name]"'),
    t('list_place_1'),
    t('All'),
    t('Page'),
  );
  $export['list'] = $view;

  return $export;
}
