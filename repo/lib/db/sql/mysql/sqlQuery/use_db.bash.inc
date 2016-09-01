## ----------------------------------------------
## use_db - for easy switching of databases
##
## NOTE: Sample datasources described below!
##       NEED TO UPDATE/REFACTOR
##
## ADVISABLE USAGE:
##    use_db <new_database>
##    query_here...
## ----------------------------------------------
use_db() {
  local datasource=$1

  case "$datasource" in
    ph_provinces)
      mysql_server='1.2.3.4'
      mysql_authconfig=$HOME/etc/auth/mysql/ph_provinces.cnf
    ;;
    world_countries)
      mysql_server='5.6.7.8'
      mysql_authconfig=$HOME/etc/auth/mysql/world_countries.cnf
    ;;
        *) ## DEFAULT is ph_provinces
       mysql_server='1.2.3.4'
       mysql_authconfig=$HOME/etc/auth/mysql/ph_provinces.cnf
    ;;
  esac
} ## END: use_db()
