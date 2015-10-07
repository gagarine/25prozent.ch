<?php
/**
 * @file
 * pc_site.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function pc_site_default_rules_configuration() {
  $items = array();
  $items['rules_after_saving_a_new_user_account'] = entity_import('rules_config', '{ "rules_after_saving_a_new_user_account" : {
      "LABEL" : "After saving a new user account",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [] },
      "IF" : [
        { "NOT user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "4" : "4" } } } }
      ],
      "DO" : [
        { "redirect" : { "url" : "user\\/[account:uid]\\/edit\\/mobile" } },
        { "user_add_role" : { "account" : [ "account" ], "roles" : { "value" : { "5" : "5" } } } }
      ]
    }
  }');
  $items['rules_user_removed_mobile_phone_number'] = entity_import('rules_config', '{ "rules_user_removed_mobile_phone_number" : {
      "LABEL" : "User removed mobile phone number",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "sms_user" ],
      "ON" : { "sms_user_number_removed" : [] },
      "DO" : [
        { "user_remove_role" : { "account" : [ "user" ], "roles" : { "value" : { "4" : "4" } } } },
        { "user_add_role" : { "account" : [ "user" ], "roles" : { "value" : { "5" : "5" } } } }
      ]
    }
  }');
  $items['rules_user_validated_sms_code'] = entity_import('rules_config', '{ "rules_user_validated_sms_code" : {
      "LABEL" : "User validated SMS code",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "sms_user" ],
      "ON" : { "sms_user_number_validated" : [] },
      "DO" : [
        { "user_add_role" : { "account" : [ "user" ], "roles" : { "value" : { "4" : "4" } } } },
        { "user_remove_role" : { "account" : [ "user" ], "roles" : { "value" : { "5" : "5" } } } }
      ]
    }
  }');
  return $items;
}
