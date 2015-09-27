<?php
/**
 * @file
 * pc_politician.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function pc_politician_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'candidat';
  $feeds_importer->config = array(
    'name' => 'Candidat',
    'description' => 'Import candidat CSV',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'lastname',
            'target' => 'field_last_name',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'firstname',
            'target' => 'field_first_name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'ID_Candidate',
            'target' => 'field_id_candidate',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'ID_Candidate',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'ID_party',
            'target' => 'field_id_party',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'ID_election',
            'target' => 'field_id_election',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'gender',
            'target' => 'field_gender',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'party_short',
            'target' => 'field_party_short',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          8 => array(
            'source' => 'elected',
            'target' => 'field_elected',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'incumbent',
            'target' => 'field_incumbent',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'list',
            'target' => 'field_list',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          11 => array(
            'source' => 'list_place_1',
            'target' => 'field_list_place_1',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'LINK_facebook',
            'target' => 'field_link_facebook',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'LINK_twitter',
            'target' => 'field_link_twitter',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'district',
            'target' => 'field_taxo_canton',
            'term_search' => '0',
            'autocreate' => 0,
          ),
          15 => array(
            'source' => 'ID_list',
            'target' => 'field_id_list',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'LINK_portrait',
            'target' => 'field_link_portrait',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'LINK_photo',
            'target' => 'field_photo:uri',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'delete',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'politician',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['candidat'] = $feeds_importer;

  return $export;
}
