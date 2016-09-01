## ----------------------------------------------------------------------------
## sqlQuery() - given query in "$1", ouput the query result
##
## ----------------------------------------------------------------------------
sqlQuery() {
  local given_query="$1"
  local query_output=

  autoload_functions "use_db"

  ## load default if $mysql_authconfig NOT found yet
  ## this is to setup the default database to use.
  [[ "$mysql_authconfig" = "" ]] && use_db

  ## now, do the query
  query_output=$(echo "$given_query" | mysql --defaults-file=$mysql_authconfig \
                                              -h $mysql_server                 \
                                             --skip-column-name)

  ## return output
  echo "$query_output"
} ## END: sqlQuery()
