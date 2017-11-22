hosts = hostNames('builder') // get list of hosts with builder-label
jobs = [:]  // maps of jobs

hosts.each { host ->
    jobs["build-on-${host}"] = {
        node(host) {
            println "update and build toolchain"
            sh 'sleep 5'
        }
    }
}

stage("toolchain") { parallel jobs }




@NonCPS
def hostNames(label) {
    def nodes = []
    jenkins.model.Jenkins.instance.computers.each { c ->
        if (c.node.labelString.contains(label)) {
            nodes.add(c.node.selfLabel.name)
        }
    }
    return nodes
}
