ko.punches.enableAll();

function set_values(obj) {
  var json = JSON.stringify(obj);
  return axios.post('https://api.keyvalue.xyz/15215c2f/myKey/' + json);
}
function get_values() {
  return axios.get('https://api.keyvalue.xyz/15215c2f/myKey');
}

var settings = {
  people: [
    'alok', 'rakshit', 'tony', 'yng shan', 'olga', 'aggelos',
    'amin', 'andrey', 'eric', 'jb', 'ravi', 'ronak', 'shahrizal', 
    'stanly', 'wei sheng', 'dmitry', 'anton'
  ],
  voted: [],
  places: [
    {name: 'Moghul Mahal', by: 'amin', votes: 0},
  ]
};

function ViewModel() {
  this.places = ko.observable([
    { name: 'loading ...', by: '', votes: 0},
  ]);
  this.voted = ko.observable([]);
  this.people = ko.observable(settings.people);
  this.user = ko.observable('');
  this.place = ko.observable('');
  that = this;

  get_values().then(function(res) {
    that.places(res.data.places);
    that.voted(res.data.voted);
    that.people(res.data.people);
  });

  this.vote = function(index) {
    var name = this.user();
    if(!name) { alert('(▰˘◡˘▰): please add your name'); return; }
    if(this.people().indexOf(name) == -1) {
      alert('ಥ_ಥ, your are not one of ' + this.people().map(function(v) { return '"'+v+'"'; }).join(', '));
      return;
    }
    if(this.voted().indexOf(name) != -1) {
      alert('ಠ益ಠ, your have already voted ' + name);
      return;
    }
    var places = this.places();
    places[index()].votes += 1;
    var voted = this.voted();
    voted.push(name);

    set_values({places: places, voted: voted, people: this.people()})
      .then(function() {
        location.reload();
      });
  }
  this.add_place = function() {
    var name = this.user();
    if(!name) { alert('(▰˘◡˘▰): please add your name'); return; }
    if(this.people().indexOf(name) == -1) {
      alert('ಥ_ಥ, your are not one of ' + this.people().map(function(v) { return '"'+v+'"'; }).join(', '));
      return;
    }
    var place = this.place();
    if(!place) { alert('(▰˘◡˘▰): please add a place'); return; }

    var places = this.places();
    places.push({name: place, votes: 0, by: name});
    var voted = this.voted();
    var people = this.people();

    set_values({places: places, voted: voted, people: people})
      .then(function() {
        location.reload();
      });
  };

  this.total = ko.computed(function() {
    var places = this.places();
    var total = 0;
    for(var i = 0; i < places.length; ++i)
      total += places[i].votes;
    return total;
  }, this);
};

ko.applyBindings(window.vm = new ViewModel());

