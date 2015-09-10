'use strict';
/**
 * Import plugins
 */
var gulp          = require('gulp'),
    $             = require('gulp-load-plugins')(),
    config        = require('./gulp_config.json'),
    runSequence   = require('run-sequence');


require(config.tasks + 'vendors')();            // $ gulp vendors
require(config.tasks + 'images')();             // $ gulp img
require(config.tasks + 'styles')();             // $ gulp styles
require(config.tasks + 'scripts')();            // $ gulp scripts
require(config.tasks + 'favicons')();           // $ gulp favicons


/**
 * Task to build assets on production server
 */
gulp.task('build', function() {
  return gulp.start('styles', 'scripts');
});

/**
 * Default task
 */
gulp.task('default', function(done){
  runSequence( ['styles', 'scripts'], done);
});
