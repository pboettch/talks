node {
    def output = sh script: 'find /bin', returnStdout: true
    output.trim()
    files = output.split("\n")
}

jobs = [:]

files.each() { f ->
    jobs['test-' + f] = {
        node {
            println f
        }
    }
}

stage('printing') {
    parallel jobs
}
