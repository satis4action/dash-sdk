#!/usr/bin/perl -w

#
# perl example to enumerate instances of CIM_ComputerSystem
# written by warptrosse@gmail.com
#

use strict;
use warnings;
use lib '../../../build/bindings/perl';
use lib '..';
use openwsman;

# debug (to stderr)
# openwsman::set_debug(1);

# Create client instance.
# (host, port, path, scheme, username, password)
my $client = new openwsman::Client::('localhost', 5985, '/wsman', 'http',
                                     'wsman', 'secret')
    or die print "[ERROR] Could not create client handler.\n";

# Alternate way.
# my $client = new openwsman::Client::('http://wsman:secret@localhost:8889/wsman')
#  or die print "[ERROR] Could not create client handler.\n";

# Set up client options.
my $options = new openwsman::ClientOptions::()
    or die print "[ERROR] Could not create client options handler.\n";

# Force basic auth.
$client->transport()->set_auth_method($openwsman::BASIC_AUTH_STR);

my $uri = 'http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ComputerSystem'; # Uri.
my $result; # Used to store obtained data.
my @list;   # Instances list.

# Enumerate from external schema (uri).
# (options, filter, resource uri)
$result = $client->enumerate($options, undef, $uri);
unless($result && $result->is_fault eq 0) {
    die print "[ERROR] Could not enumerate instances.\n";
}

# Get context.
my $context = $result->context();

while($context) {
    # Pull from local server.
    # (options, filter, resource uri, enum context)
    $result = $client->pull($options, undef, $uri, $context);
    next unless($result);

    # Get nodes.
    # soap body -> PullResponse -> items
    my $nodes = $result->body()->child()->child()->child();
    next unless($nodes);

    # Get items.
    my $items;
    for((my $cnt = 0) ; ($cnt<$nodes->size()) ; ($cnt++)) {
        $items->{$nodes->get($cnt)->name()} = $nodes->get($cnt)->text();
    }
    push @list, $items;

    $context = $result->context();
}

# Release context.
$client->release($options, $uri, $context) if($context);

# Print output.
foreach(@list) {
    print "---------------------------------------------------\n";
    my %route = %$_;
    foreach my $key (keys %route) {
        print $key,": ",$route{$key},"\n";
    }
    print "---------------------------------------------------\n";
}
