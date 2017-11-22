node('master') {
    println "update and build toolchain"
    sh 'sleep 5'
}

node('slave0') {
    println "update and build toolchain"
    sh 'sleep 5'
}
