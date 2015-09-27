<?php
/**
 * @file
 * pc_politician.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function pc_politician_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'candidat-district-required';
  $feeds_tamper->importer = 'candidat';
  $feeds_tamper->source = 'district';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['candidat-district-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'candidat-firstname-required';
  $feeds_tamper->importer = 'candidat';
  $feeds_tamper->source = 'firstname';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['candidat-firstname-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'candidat-gender-required';
  $feeds_tamper->importer = 'candidat';
  $feeds_tamper->source = 'gender';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['candidat-gender-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'candidat-id_candidate-required';
  $feeds_tamper->importer = 'candidat';
  $feeds_tamper->source = 'ID_Candidate';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['candidat-id_candidate-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'candidat-id_election-required';
  $feeds_tamper->importer = 'candidat';
  $feeds_tamper->source = 'ID_election';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['candidat-id_election-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'candidat-id_party-required';
  $feeds_tamper->importer = 'candidat';
  $feeds_tamper->source = 'ID_party';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['candidat-id_party-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'candidat-lastname-required';
  $feeds_tamper->importer = 'candidat';
  $feeds_tamper->source = 'lastname';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['candidat-lastname-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'candidat-link_photo-rewrite';
  $feeds_tamper->importer = 'candidat';
  $feeds_tamper->source = 'LINK_photo';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => 'https://smartvote.ch[link_photo]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite';
  $export['candidat-link_photo-rewrite'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'candidat-party_short-required';
  $feeds_tamper->importer = 'candidat';
  $feeds_tamper->source = 'party_short';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array(
    'invert' => 0,
    'log' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Required field';
  $export['candidat-party_short-required'] = $feeds_tamper;

  return $export;
}
