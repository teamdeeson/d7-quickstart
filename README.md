# Deeson D7 QuickStart.

Welcome to the repository of the *D7 QuickStart* project. Thank you for choosing to work on this project.

## Prerequisites.

You'll need to be running [Docker](https://www.docker.com/) and the [Deeson Docker Proxy](https://github.com/teamdeeson/docker-proxy) to run this project locally.

## Getting started.

1. Clone the repo.
2. `make install`
3. `make start`
4. Add a database dump e.g. 

```
drush @test sql-dump > test.sql
pv test.sql | docker-compose exec -T mariadb mysql -udrupal -pdrupal drupal
```

6. Prepare the database for local usage `make update`
5. Login for the first time `drush @docker uli`

## Subsequent runs.

1. Start Docker: `make start`
2. Login: `drush @docker uli`

## When done.

Stop Docker to save resources: `make stop`

## Updating this project.

This project uses [Drush Make](https://docs.drush.org/en/7.x/make/) for pulling in dependencies.

### Updating modules.

You should edit the versions defined in `drush-make.lock.yml`

### Updating core.

No special considerations for this project, just edit the `drush-make.lock.yml`

## Patching the project.

Patches should be referenced from Drupal.org where possible. If you must make a patch file store it in the patches directory in the project root.  Patches are then referenced in the `drush-make.yml` file as appropriate.

```
projects:
  module_name:
    patch:
      # A comment about a local patch file and what it does.
      - './patches/some-custom-file.patch'
      # A comment about a patch on drupal.org and what it does.
      - https://drupal.org/files/some-patch.patch
```

## Branching strategy.

We use [GitFlow](https://www.deeson.co.uk/labs/using-git-flow-drupal-project) branching strategy on this project.

## Deployment.

The `bitbucket-pipelines.yml` file describes the build process which is execute on commit to specified branches in BitBucket.

## Hosting.

This project is hosted on **insert hosting provider details here**.

## Environmental configuration management.

This project uses:

* Features module for exporting database artifacts
* [master module](https://www.deeson.co.uk/labs/drupal-7-environment-dependency-management-master-module) for specifying per environment module requirements
* An organised approach to [settings.php environmental variables](https://www.deeson.co.uk/labs/site-configuration-strategy-or-how-manage-your-settingsphp-files) via the `sites/all/conf` directory.
* Secure environment settings should not be in version control and managed via the hosting environment variables.

## Jira project management.

Tickets are managed in this [Jira project]() **<--Add link here**
