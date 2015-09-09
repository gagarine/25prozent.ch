<?php // $Id$

/**
 * @file
 * Provides views support for the Entity Relationships module.
 */

/**
 * Implements hook_views_handlers().
 */
//function er_views_views_handlers() {
//  return array(
//    'info' => array(
//      'path' => drupal_get_path('module', 'er_views'),
//    ),
//    'handlers' => array(
//      'er_views_handler_field_er_role' => array(
//        'parent' => 'views_handler_field',
//      )
//
//    ),
//  );
//}

/**
 * Implements hook_views_data().
 */
function er_views_views_data() {
  $data = array();

  //----------------------------------------------------------------------------
  //er_role table

  $data['er_role']['table']['group'] = t('Entity Relationship Roles');
  $data['er_role']['table']['base'] = array(
    'field' => 'rid',
    'title' => t('Relationship Role'),
    'help' => t('Relationship Roles describe the the role of each party in a Relationship Definition.'),
  );

  // ----------------------------------------------------------------
  // Fields

  // cid
  $data['er_role']['rid'] = array(
    'title' => t('ID'),
    'help' => t('The ID of the relationship role'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
    ),
  );

  // machine_name
  $data['er_role']['machine_name'] = array(
    'title' => t('Machine Name'),
    'help' => t('The machine name of the relationship role.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    )
  );

  // name
  $data['er_role']['name'] = array(
    'title' => t('Name'),
    'help' => t('The human-friendly name of the relationship role.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    )
  );

  // description
  $data['er_role']['description'] = array(
    'title' => t('Description'),
    'help' => t('The description of the relationship role.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  //----------------------------------------------------------------------------
  //er_definition table

  $data['er_definition']['table']['group'] = t('Entity Relationship Definitions');
  $data['er_definition']['table']['base'] = array(
    'field' => 'did',
    'title' => t('Relationship Definition'),
    'help' => t('Relationship Definitions describe the ways two entities can be related.'),
  );

  //joins
  //TODO: How to join the party_from_type & party_to_type fields? call hook_entity_info? Do what with it?
  $data['er_definition_role_from']['table']['join'] = array(
    'er_role' => array(
      'table' => 'er_definition',
      'left_field' => 'rid',
      'field' => 'party_from_rid'
    )
  );

  $data['er_definition_role_to']['table']['join'] = array(
    'er_role' => array(
      'table' => 'er_definition',
      'left_field' => 'rid',
      'field' => 'party_to_rid'
    )
  );

  // ----------------------------------------------------------------
  // Fields

  // did
  $data['er_definition']['did'] = array(
    'title' => t('Definition ID'),
    'help' => t('The ID of the relationship definition'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
    ),
  );

  // machine_name
  $data['er_definition']['machine_name'] = array(
    'title' => t('Machine Name'),
    'help' => t('The machine name of the relationship definition.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    )
  );

  // name
  $data['er_definition']['name'] = array(
    'title' => t('Name'),
    'help' => t('The human-friendly name of the relationship definition.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    )
  );


  // description
  $data['er_definition']['description'] = array(
    'title' => t('Description'),
    'help' => t('The description of the relationship definition.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // party_from_type
  $data['er_definition']['party_from_type'] = array(
    'title' => t('Party "From" entity type'),
    'help' => t("TODO"),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // party_from_label
  $data['er_definition']['party_from_label'] = array(
    'title' => t('Party "From" label'),
    'help' => t("Describes the relationship FROM entity A to entity B"),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'filter' => array(
      'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

 // party_to_type
  $data['er_definition']['party_to_type'] = array(
    'title' => t('Party "To" entity type'),
    'help' => t("TODO"),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // party_to_label
  $data['er_definition']['party_to_label'] = array(
    'title' => t('Party "To" label'),
    'help' => t("Describes the relationship TO entity A from entity B"),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'filter' => array(
      'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // party_from_rid
  $data['er_definition']['party_from_rid'] = array(
    'title' => t('Party "From" entity role ID'),
    'help' => t("TODO"),
    'relationship' => array(
      'base' => 'er_role',
      'base_field' => 'rid',
      'handler' => 'views_handler_relationship',
      'label' => 'Relationship "From" Role'
    ),
  );

 // party_to_rid
  $data['er_definition']['party_to_rid'] = array(
    'title' => t('Party "To" entity role ID'),
    'help' => t("TODO"),
    'relationship' => array(
      'base' => 'er_role',
      'base_field' => 'rid',
      'handler' => 'views_handler_relationship',
      'label' => 'Relationship "To" Role'
    ),
  );

  //----------------------------------------------------------------------------
  //er instance tables
  //
  // Each ER definition gets its own instance table, so that we can dynamically
  // declare Views relationships here.  Loop through definitions and declare
  // views data info for each instance table.

  $defs = er_definition_load_multiple(FALSE);
  foreach ($defs as $def) {

    //Get info about the from/to entity types for this definition
    $from_info = entity_get_info($def->party_from_type);
    $to_info = entity_get_info($def->party_to_type);

    $table = er_get_instance_table_name($def);
    $data[$table]['table']['group'] = t('Entity Relationship Instances');
    $data[$table]['table']['base'] = array(
    'field' => 'iid',
    'title' => t('!name Relationship Instance', array('!name' => $def->name)),
    'help' => t('Establishes a relationships between !from and !to entities.', array('!from' => $def->party_from_bundle, '!to' => $def->party_to_bundle)),
    );
    // ----------------------------------------------------------------
    // Fields

    $data[$table]['iid'] = array(
      'title' => t('Instance ID'),
      'help' => t('The serial ID of the !name relationship instance', array('!name' => $def->name)),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument',
      ),

    );

    $data[$table]['did'] = array(
      'title' => t('Definition ID'),
      'help' => t('The ID of the !name relationship definition', array('!name' => $def->name)),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument',
      ),
      'relationship' => array(
        'base' => 'er_definition',
        'base_field' => 'did',
        'handler' => 'views_handler_relationship',
        'label' => 'Relationship Definition ID',
      ),
    );

    $data[$table]['party_from_id'] = array(
      'title' => t('Party "From" ID'),
      'help' => t('The ID of the "from" entity in the !name relationship instance.', array('!name' => $def->name)),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument',
      ),
      'relationship' => array(
        'base' => $from_info['base table'],
        'base_field' => $from_info['entity keys']['id'],
        'handler' => 'views_handler_relationship',
        'label' => '"From" entity ID',
      ),
    );
    $data[$table]['party_to_id'] = array(
      'title' => t('Party "To" ID'),
      'help' => t('The ID of the "to" entity in the !name relationship instance.', array('!name' => $def->name)),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument',
      ),
      'relationship' => array(
        'base' => $to_info['base table'],
        'base_field' => $to_info['entity keys']['id'],
        'handler' => 'views_handler_relationship',
        'label' => '"To" entity ID',
      ),
    );

  }

  
  return $data;
}
