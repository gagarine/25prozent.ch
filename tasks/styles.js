'use strict';

var gulp          = require('gulp'),
    $             = require('gulp-load-plugins')(),
    config        = require('../gulp_config.json'),
    argv          = require('yargs').argv

module.exports = function() {

  /**
   * Build styles from SCSS files
   * With error reporting on compiling (so that there's no crash)
   */
  gulp.task('styles', function() {
    if (argv.production) { console.log('[styles] Production mode' ); }
    else { console.log('[styles] Dev mode'); }

    return gulp.src([config.assets, config.assets + 'style.scss'])
      .pipe($.if(!argv.production, $.sourcemaps.init()))
      .pipe($.sass({
        outputStyle: 'nested', // libsass doesn't support expanded yet
        precision: 10,
        includePaths: ['.']
      }).on('error', $.sass.logError))
      // .pipe($.postcss([
      //   require('autoprefixer-core')({
      //     browsers: config.browsers,
      //     options: {
      //       map: true
      //     }
      //   })
      // ]))
      .pipe($.if(!argv.production, $.sourcemaps.write()))
      .pipe($.if(argv.production, $.minifyCss()))
      .pipe($.concat('style.css'))
      .pipe($.size({title: 'STYLES', showFiles: true}))
      .pipe(gulp.dest(config.build + '/'));
  });

};
