import { StatusBar } from 'expo-status-bar';
import React, { Image, Component } from 'react';
import { Text, TextInput, View, FlatList, TouchableOpacity } from 'react-native';
import { back, texts, buttons, views, images, home } from './styles'
import { description_space, info_list, reaction_bar } from './styles_flatlist'
import Icon from 'react-native-vector-icons/FontAwesome'
import Icon_Feather from 'react-native-vector-icons/MaterialCommunityIcons'
import Icon_Param from 'react-native-vector-icons/MaterialIcons'
import ProfilePicture from 'react-native-profile-picture'
import data from '../assets/posts_data'
import RNUrlPreview from 'react-native-url-preview';

import firebase from 'firebase'
import "firebase/firestore"

const Info_Item = ({ image, pseudo, date }) => (
    <View style={info_list.container}>
        <View style={{ flex: 1, paddingRight: 10 }} >
            <ProfilePicture
                isPicture={true}
                requirePicture={require('../assets/profile_image.jpg')}
                shape='circle'
                height={30}
                width={30}
            />
        </View>
        <View style={{ flex: 8, alignContent: 'center', justifyContent: 'center' }} >
            <Text style={texts.pseudo_for_posts}>{pseudo}</Text>
        </View>
        <View style={{ flex: 4, alignContent: 'center', justifyContent: 'center' }}>
            <Text style={texts.pseudo_for_posts}>{date}</Text>
        </View>
    </View>
);

const Preview = ({ link }) => (
    <RNUrlPreview text={link} />
);

const Reaction_Bar = () => (
    <View style={reaction_bar.container}>
        <View style={{ flex: 1 }} >
            <Icon name="thumbs-up" size={32} color="#5A5A5A" />
        </View>
        <View style={{ flex: 1, alignContent: 'center', justifyContent: 'center' }} >
            <Icon_Feather name="message" size={32} color="#5A5A5A" />
        </View>
        <View style={{ paddingLeft: 5, flex: 1, alignContent: 'center', justifyContent: 'center' }}>
            <Icon name="share" size={32} color="#5A5A5A" />
        </View>
        <View style={{ paddingLeft: 5, flex: 1, alignContent: 'center', justifyContent: 'center' }}>
            <Icon name="flag" size={32} color="#5A5A5A" />
        </View>
        <View style={{ paddingLeft: 5, flex: 3, alignContent: 'center', justifyContent: 'center' }}>
            <Icon name="send" size={32} color="#5A5A5A" />
        </View>
        <View style={{ flex: 1, alignContent: 'center', justifyContent: 'center' }}>
            <Icon_Param name="settings" size={32} color="#5A5A5A" />
        </View>
        <View style={{ flex: 1, alignContent: 'center', justifyContent: 'center' }}>
            <Icon name="bookmark" size={32} color="#5A5A5A" />
        </View>
    </View>
);

const Description = ({ description, nb_comments }) => (
    <View style={description_space.container}>
        <Text style={{ marginTop: 5, color: "#5A5A5A" }}>{description}</Text>
        <TouchableOpacity>
            <Text style={description_space.comments}>voir {nb_comments} commentaires</Text>
        </TouchableOpacity>
    </View>
);

const Item = ({ id, nbLike, image, pseudo, date, link, nb_comments, description }) => (
    <View style={views.container}>
        <Info_Item image={image} pseudo={pseudo} date={date} />
        <Preview link={link} />
        <Reaction_Bar />
        <Description description={description} nb_comments={nb_comments} />
    </View>
);

const renderItem = ({ item }) => (
    <Item id={item.id} nbLike={item.nb_like} image={item.autor_image} pseudo={item.autor_pseudo} date={item.post_date} link={item.link} nb_comments={item.nb_comments} description={item.description} />
);
export default class MyHomePage extends React.Component {
    render() {
        return (
            <View style={{ flex: 1 }}>
                <View style={views.top_bar}>
                    <View style={{ flex: 1, alignItems: 'center', justifyContent: 'center', paddingTop: 25 }}>
                        <TouchableOpacity onPress={() => this.props.navigation.navigate('Profile')}>
                            <ProfilePicture
                                isPicture={true}
                                URLPicture={firebase.auth().currentUser.photoURL}
                                shape='circle'
                                width={75}
                                height={75}
                            />
                        </TouchableOpacity>
                    </View>
                    <View style={{ flex: 2, alignItems: 'center', justifyContent: 'center', paddingTop: 25 }}>
                        <Text style={texts.title_of_page}>Garrasi</Text>
                    </View>
                    <View style={{ flex: 1, alignItems: 'center', justifyContent: 'center', paddingTop: 35 }}>
                        <Icon name="send" size={40} color="#5A5A5A" onPress={() => this.props.navigation.navigate('Dm')} />
                    </View>
                </View>
                <View style={views.container}>
                    <View style={home.view_rechercher}>
                        <TextInput style={home.bar_rechercher} placeholder="Rechercher" />
                        <FlatList
                            data={data}
                            keyExtractor={(item) => item.id.toString()}
                            renderItem={renderItem}
                        />
                    </View>
                </View>
                <View style={views.bottom_bar}>
                    <View style={{ flex: 1, alignItems: 'center', justifyContent: 'center' }}>
                        <Icon name="home" size={55} color="#5A5A5A" onPress={() => this.props.navigation.navigate('Profile')} />
                    </View>
                    <View style={{ flex: 1, alignItems: 'center', justifyContent: 'center' }}>
                        <Icon name="plus" size={55} color="#5A5A5A" onPress={() => this.props.navigation.navigate('Add')} />
                    </View>
                    <View style={{ flex: 1, alignItems: 'center', justifyContent: 'center' }}>
                        <Icon name="bookmark" size={55} color="#5A5A5A" onPress={() => this.props.navigation.navigate('Profile')} />
                    </View>
                </View>
                <StatusBar style="auto" />
            </View>
        )
    }
}

export { renderItem };