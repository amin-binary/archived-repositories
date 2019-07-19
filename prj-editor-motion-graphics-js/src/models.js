import {observable} from 'mobx';

class XY {
    @observable x = 0;
    @observable y = 0;
}

class Attributes {
    @observable stroke = '#000';
    @observable stroke_width = 1;
    @observable fill = 'none';
};

export class Path extends Attributes {
    @observable d = null;
};

export class Line extends Attributes {
    @observable start = new XY();
    @observable end   = new XY();
};


export class Group extends Attributes {
    @observable children = [];
    @observable size = new XY();
    @observable position = new XY();
    @observable rotate = null;
}

export class Artboard extends Group {
    @observable name = 'artboard';
}

export class Page {
    @observable name = 'page';
    @observable artboards = []; // artboards
    // TODO: figure out how zoom & moving would work
};
