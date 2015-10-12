# config valid only for current version of Capistrano
lock '3.4.0'

set :application, '25prozent'
set :repo_url, 'git@github.com:gagarine/25prozent.ch.git'

# Path to the drupal directory, default to app.
set :app_path,        "app"

# Default branch is :master
# ask :branch, `git rev-parse --abbrev-ref HEAD`.chomp

# Default deploy_to directory is /var/www/my_app_name
# set :deploy_to, '/var/www/my_app_name'

# Default value for :scm is :git
# set :scm, :git

# Default value for :format is :pretty
# set :format, :pretty

# Default value for :log_level is :debug
# set :log_level, :debug

# Default value for :pty is false
# set :pty, true

# Link file settings.php
set :linked_files, fetch(:linked_files, []).push('app/sites/default/settings.php', 'app/.htaccess')

# Link dirs files and private-files
set :linked_dirs, fetch(:linked_dirs, []).push('app/sites/default/files', 'private-files')

# Default value for default_env is {}
# set :default_env, { path: "/opt/ruby/bin:$PATH" }

# Default value for keep_releases is 5
# set :keep_releases, 5


# Remove default composer install task on deploy:updated
Rake::Task['deploy:updated'].prerequisites.delete('composer:install')

# Map composer and drush commands
# NOTE: If stage have different deploy_to
# you have to copy those line for each <stage_name>.rb
# See https://github.com/capistrano/composer/issues/22
SSHKit.config.command_map[:composer] = "#{shared_path.join("composer.phar")}"
SSHKit.config.command_map[:drush] = "#{shared_path.join("vendor/bin/drush")}"

namespace :deploy do

  after :restart, :clear_cache do
    on roles(:web), in: :groups, limit: 3, wait: 10 do
      # Here we can do anything such as:
      # within release_path do
      #   execute :rake, 'cache:clear'
      # end
    end
  end

end


