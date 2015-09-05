# Entity Relationships dev tasks

* TODO use hook_entity_load/_view instead of node-specific functions

* TODO Node->bundle support for the settings page and from/to entity type pulldowns, E.G.

Node
 -Page
 -Article
 -...
User
 -User

* TODO auto-populate machine name

* TODO Add plural fields for entity role; "Parent" "Parents" "Child" "Children"

* TODO Add token support for the from/to labels; '%from is the parent of %to', '%to is the child of %from'

* TODO RDF integration

* Implement hook_field_atatch_rename_bundle() to preserve relationships when bundle names change

* Exportables support

* Views integration

* Add label_callback info to hook_entity_info()

* TODO check/warning if no roles or content types have been created/enabled

* TODO refactor with http://api.drupal.org/api/drupal/includes--common.inc/function/entity_extract_ids/7