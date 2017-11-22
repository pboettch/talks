types = ['Release', 'RelWithDebInfo', 'Debug', 'Config1', 'Config2']
jobs = [:]  // maps of jobs

types.each { type ->
    jobs["build-${type}"] = {
        node('builder') {
            sh 'echo echo Hello, World, ' + type +' \\$1 > test.sh'
            sh 'chmod +x test.sh'
            sh 'sleep 3'
            stash name: "exe-${type}",
                  includes: "test.sh"
        }
    }
}

stage("programs") { parallel jobs }

jobs = [:]  // maps of jobs

types.each { type ->
    for (i = 0; i < 10; i++) {
        jobs["test-${type}-${i}"] = {
            node('tester') {
                unstash "exe-${type}"
                sh "./test.sh ${i}"
                sh 'sleep 0.5'
            }
        }
    }
}

stage("tests") { parallel jobs }
