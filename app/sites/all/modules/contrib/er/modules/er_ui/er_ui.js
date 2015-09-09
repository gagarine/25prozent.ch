// $Id$

(function ($) {

Drupal.behaviors.erFieldsetSummaries = {
  attach: function (context) {
    $('fieldset.entity-relationship-form', context).drupalSetSummary(function (context) {
      return Drupal.checkPlain(Drupal.settings.er_ui.erRelationshipCount);
    });
  }
};

})(jQuery);