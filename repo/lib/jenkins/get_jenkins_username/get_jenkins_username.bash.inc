## output jenkins username if it's in jenkins environment.
## $FAILED(1) otherwise.
get_jenkins_username() {

  local retval=$FAILED

  [[ ! -z "$JENKINS_HOME" ]] && {
    retval=$($CURL_BIN -s --noproxy \* ${BUILD_URL}api/xml?xpath=//userId|$SED_BIN "s/<[^>]\+>//g")
  }

  echo $retval
} ## END: get_jenkins_username()
